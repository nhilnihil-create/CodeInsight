#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    pair<long long,long long> d[n];
    for(int i=0;i<n;i++)cin >> d[i].second >> d[i].first;
    sort(d,d+n);
    int count=0;
    int flag=1;
    for(int i=0;i<n;i++){
        count+=d[i].second;
        if(count>d[i].first)flag=0;

    }
    if(flag)cout << "Yes";
    else cout << "No";
}