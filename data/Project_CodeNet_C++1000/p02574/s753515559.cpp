/* Ahmed Maher ( Acro_14 ) */
/*while(WA)try();*/
#include <bits/stdc++.h>
typedef long long ll;
const ll oo = 0x3f3f3f3f;
int const N = 1e6+5;
int const mod = 1e9+7;
using namespace std;
/*string Alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabet="abcdefghijklmnopqrstuvwxyz";*/
 int fact[1000005];
bool f=false;
void gcd(int x){
        if(f==true)
            return;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                int a=i;
                int b=x/i;
                if(a==b){
                    a=i;
                    b=1;
                }
                if(a!=1){
                    if(fact[a]){
                        f=true;
                        return;
                    }
                    fact[a]++;
                }
                if(b!=1){
                    if(fact[b]){
                        f=true;
                        return;
                    }
                    fact[b]++;
                }
            }
        }
}
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    {
        gcd(arr[i]);
        result = __gcd(arr[i], result); 
    }
    return result; 
} 
void solve(){
	int n;
	cin>>n;
	int arr[n];	

	for(int i=0;i<n;i++)cin>>arr[i];

    int GCD = findGCD(arr,n);

    if(!f) cout<<"pairwise coprime";
    else if(GCD==1)cout<<"setwise coprime";
    else cout<<"not coprime";
   
  
	cout<<endl;
}

int main()
{
  int t;
	t=1;
     while(t--)
    {
       
		solve();
 
    }
	return 0;
}
 
//       int anss[t+1]; 
//            anss[j]=ans;
//     for(int j=1;j<=t;j++) printf("Case %d: %d\n",j,anss[j]);