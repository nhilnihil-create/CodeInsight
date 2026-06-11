#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> ba(n,vector<int>(2));
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>ba[i][1]>>ba[i][0];
        sum+=ba[i][1];
    }
    sort(ba.begin(),ba.end(),greater<>());
    for(int i=0;i<n;i++){
        if(sum>ba[i][0]){
            cout<<"No"<<endl;
            return 0;
        }else{
            sum-=ba[i][1];
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
