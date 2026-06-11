#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array


ll n;


void solve(){
    
    cin >> n;


    
    
    string s;
    ll t;
    int max = 0;
    ll tmp = 26;
    ll z = 0;
    while (max < 11 && n > 0)
    {

        t = n % tmp;
        t = t / (tmp/26);

        if(t == 0) t = 26;

        //cout << "n : " << n << " tmp: " << tmp << " "<< t  << "char : " << char(t+'a'-1)<< endl;
        s += char(t+'a'-1);

        n = n-(t * (tmp/26)); 

        tmp = tmp*26;
    }
    

    reverse(s.begin(), s.end());
    cout << s << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}