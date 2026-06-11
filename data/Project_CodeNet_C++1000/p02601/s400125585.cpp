/*
author:Rahul Chocha
school of eng. and applied science
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MAXI INT_MAX
#define MINI INT_MIN
#define din(t) long long t; cin >> t;
#define fi(i, l, r, d) for (i = l; i < r; i += d)
#define fd(i, l, r, d) for (i = l - 1; i >= r; i -= d)
#define pb push_back
#define mp make_pair


void speed_up()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}
void Inp_Out(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("A.01.inp", "r", stdin);
    // for writing output to output.txt
    //freopen("A.01.out", "w", stdout);
    #endif
}

int main()
{   

   	speed_up();
   	//Inp_Out();

		din(a) din(b) din(c) din(k);
		ll flg=1;
		if(a>=pow(2,k)*b)flg=0;
		else {
			ll i=0;
			while(a>=b && i<=k){
				b*=2;
				//cout<<b<<"\n";
				i++;
			}
			k-=(i);
			//if(!k)flg=0;
		}
		if(b>=c*pow(2,k))flg=0;
		//cout<<a<<" "<<b<<" "<<c;
		if(flg)cout<<"Yes\n";
		else cout<<"No\n";
	
	

} 
