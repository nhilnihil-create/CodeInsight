/*
    /\ In The Name Of ALLAH /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

int a[N];
int main()
{
    int n; cin>>n;
    ll cnt = 0;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
        if(i){
            if(a[i] < a[i-1]) cnt += a[i-1] - a[i],a[i] = a[i-1];
        }
    }
    cout<<cnt<<endl;
}
