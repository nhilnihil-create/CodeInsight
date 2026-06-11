#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 2e5+5;
ll int arr[sz]={0},arr1[sz]={0};
//ll int arr[100][100]= {0};
int prime[10005]= {0};
//vector <ll int> vec,vec1,vec2;
set <pair <int,int>> st;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


int main()
{
    string s;
    cin>>s;

    if(s[0]=='7' || s[1]=='7' || s[2]=='7')
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
