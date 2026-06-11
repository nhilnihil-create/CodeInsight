// #include<bits/stdc++.h>
// using namespace std;
 
// const int N = 1000000000, MAXI = N, D = 14;
 
// int main() {
//     freopen("output.txt", "r", stdin);
//     freopen("input.txt", "w", stdout);
//     srand(time(nullptr));
//     int tc = 5, flag = 1;
//     cout << tc << "\n";
//     while (tc--)
//     {
//         int a = rand()%N+1;
//         a *= flag;
      
//         flag *= -1;

//         int b = rand()%MAXI + 1, c;

//         int d = rand()%D + 1;

//         int flag2 = rand()%3, k;

//         if(flag2==0)
//         {
//         	k = rand()%d+1;
//         	c = a + k*b;
//         }
//         else if(flag2==1)
//         {
//         	k = rand()%d + 1;
//         	c = a - k*b;
//         }
//         else
//         	c = rand()%MAXI;

//         cout << a << " " << b << " " << c << " " << d;
//         cout << "\n";
//         cout << "~\n";
//     }
 
//     return 0;
// }
 
 
 
 
 
 
 
 
//---------------------------------------------//
 
 
 
/*
#define int long long 
#define mod (int)(1e9+9)
#define endl '\n'
#define MAXI (int)(3e17+10)
#define N 200005
 */ 
 
 
 
 
 
 
//  /* while(!cin.eof()) */
 
#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define mod (int)(1e9+7)
#define endl '\n'
#define MAXI (int)(3e17+10)
#define N 100005


int power(int a,int m1)
{
    if(m1==0)return 1;
    else if(m1==1)return a;
    else if(m1==2)return (1LL*a*a)%mod;
    else if(m1&1)return (1LL*a*power(power(a,m1/2),2))%mod;
    else return power(power(a,m1/2),2)%mod;
}



int fun(int k, int n)
{
	if(k==1)
		return 1;
	int x = power(k, n);
	int y = power(k-1, n);

	return (x - y + mod)%mod;
}
 

// Driver code to test above functions
int32_t main()
{
   
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
 
    
   	int n, k;
   	cin >> n >> k;
   	
   	vector<int> dp(k+1, 0);

   	for(int i=k;i>=1;i--)
   	{
   		int x = k/i;

   		int temp = power(x, n);
   		int extra = 0;
   		for(int j=2*i;j<=k;j+=i)
   			extra = (extra + dp[j])%mod;

   		dp[i] = (temp - extra + mod)%mod;

   		ans += (1LL*i*dp[i])%mod;
   	}

    cout << ans%mod;

    return 0;
 
} 