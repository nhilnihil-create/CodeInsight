#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
 
int main(){
    long long n,k;cin>>n>>k;
    long long t;
    map<long long, long long> teleporters;
    for (long long i=0;i<n;i++){
        cin >> t;
        teleporters[i+1] = t;
    }
    long long present_location = 1;
    bool cycle = false;
    long long cycle_length = 0;
    vector<long long> past_positions(n+1);
    set<long long> appeared_factors;
    for (long long i=0;i<k;i++){
        present_location = teleporters[present_location];
        if (appeared_factors.find(present_location) != appeared_factors.end()){
            cycle = true;
            cycle_length = i - distance(past_positions.begin(), find(past_positions.begin(), past_positions.end(), present_location)) + 1;
            break;
        } else {
            past_positions[i+1] = present_location;
            appeared_factors.insert(present_location);
        }
    }
    if (cycle){
        long long cycle_start_point = distance(past_positions.begin(), find(past_positions.begin(), past_positions.end(), present_location));
        long long remain = k - cycle_start_point;
        cout << past_positions[cycle_start_point + (remain % cycle_length)] << endl;
 
    } else {
        cout << present_location << endl;
    }
    return 0;
}