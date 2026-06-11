#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> p;
    int i;
    for(i=0;i<n;i++){
        int f;
        cin >> f;
        p.push_back(f);
    } 

    sort(p.begin(),p.end());
    int sum=0;;
    for(i=0;i<k;i++){
        sum += p.at(i);
    } 

    cout << sum << endl;
}