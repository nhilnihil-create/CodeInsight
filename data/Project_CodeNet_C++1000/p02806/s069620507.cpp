#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    int n,time=0;
    cin>>n;
    vector<string> s(n);
    vector<int>t(n);
    for(int i=0;i<n;i++)   cin>>s[i]>>t[i];
    string x;
    cin>>x;
    vector<string>::iterator itr = find(s.begin(),s.end(),x);
    int j=distance(s.begin(),itr);
    for(int k=j+1;k<n;k++) time+=t[k];
    cout<<time<<endl;
    return 0;
}