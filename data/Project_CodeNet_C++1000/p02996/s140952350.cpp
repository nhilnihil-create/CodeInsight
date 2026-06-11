#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main(void){
    // Your code here!
    int N;
    cin >> N;
    vector<pair<int,int> >jobs ;
    for(int i = 0;i  < N; i++){
        int a,b;
        cin >> a >> b;
        auto tmp = pair(b,a);
        jobs.push_back(tmp);
    }
    sort(jobs.begin(), jobs.end());
    
    int time = 0;
    for(int i =0; i < N; i++){
        time += jobs[i].second;
        if(time > jobs[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
    
}
