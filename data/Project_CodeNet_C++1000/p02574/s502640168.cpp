#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
const int MAX = 1E6;

int n;
int a[N];
int G;
bool vis[N],flag;

int prime[N] = {0},num_prime = 0;      
bool isNotPrime[N] = {1, 1};
int sieve(int n)
{
	for(int i = 2 ; i < n ; i ++)         
    {              
    if(! isNotPrime[i])            
        prime[num_prime ++]=i;
	for(int j = 0 ; j < num_prime && i * prime[j]<  N ; j ++)  
        {                 
        	isNotPrime[i * prime[j]] = 1;
            if( !(i % prime[j] ) )  
	            break;             
        }          
    }    
    
    return num_prime;
}
//vector<pair<int,int> > res;
void prime_divide(int x)
{
	if(!flag)	return ;
	for(int i=0;i<num_prime;i++)
	{
		int nowprime = prime[i];
		if(nowprime*nowprime > x)	break;
		if(x%nowprime)	continue;
		//res.emplace_back(nowprime,0);
	//	do
		//{
		//	res.back().second++;
		//}while((x /= nowprime)%nowprime == 0);
		if(vis[nowprime] == true)
		{
			flag = false;
			break;
		}
		vis[nowprime] = true;
		while((x /= nowprime)%nowprime == 0);
	}
	if(!flag)	return ;
	if(x!=1)	
	{
		if(vis[x] == true)
			flag = false;
		else vis[x] = true;
	}
	return ;
	//if(x!=1)	res.emplace_back(x,1);
	
 } 


int main()
{
	scanf("%d",&n);
	sieve(MAX);
	memset(vis,false,sizeof(vis));
	flag = true;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i==1)	G = a[i];
		else	G = __gcd(G,a[i]);
		prime_divide(a[i]);
	}	
	if(G!=1)
	{
		printf("not coprime\n");
		return 0;
	}
	if(flag)	printf("pairwise coprime\n");
	else printf("setwise coprime\n");
	
	
	return 0;
}