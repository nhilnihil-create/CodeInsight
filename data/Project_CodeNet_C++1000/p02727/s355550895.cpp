#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int x,y,a,b,c;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    cin >> x >>y >> a >> b >> c;
    int delicious;
    while(a--){
        cin >> delicious;
        v1.push_back(delicious);
    }
    while(b--){
        cin >> delicious;
        v2.push_back(delicious);
    }
    while(c--){
        cin >> delicious;
        v3.push_back(delicious);
    }
    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end(),greater<int>());
    //sort(v3.begin(),v3.end(),greater<int>());
    for(int i=0;i<x;i++)
        v3.push_back(v1[i]);
    for(int i=0;i<y;i++)
        v3.push_back(v2[i]);
    sort(v3.begin(),v3.end(),greater<int>());
    long long ans = 0 ;
    for(int i=0;i<x+y;i++)
        ans+=v3[i];
    cout << ans << endl;
    return 0;
}
