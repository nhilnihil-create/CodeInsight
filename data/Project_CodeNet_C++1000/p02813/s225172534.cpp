#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a=0,b=0,counter=0;
    cin>>n;
    vector<int>p(n),q(n),s(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> q[i];
    iota(s.begin(), s.end(), 1);                //assignment operator iota
    do
    {
        if(s == p)
            a = counter;
        if(s == q) 
            b = counter;
        counter++;
    }while(next_permutation(s.begin(), s.end()));

    cout<<abs(b-a)<<endl;
}