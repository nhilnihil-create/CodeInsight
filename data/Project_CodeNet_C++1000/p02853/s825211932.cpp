#include <bits/stdc++.h>

using namespace std;

typedef long long lo;
typedef pair< lo,lo > PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)

const lo MAX = -1000000000000000000;
const lo MIN = 1000000000000000000;
const lo inf = 1000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 500005;
const lo mod = 1000000007;

int n,m,b[li],a[li],k,flag,t;
int cev;
string s;
vector<int> v;

int main(void){
	scanf("%d %d",&n,&m);
	if(n==1 && m==1)cev+=400000;
	if(n==1)cev+=300000;
	if(m==1)cev+=300000;
	if(n==2)cev+=200000;
	if(m==2)cev+=200000;
	if(n==3)cev+=100000;
	if(m==3)cev+=100000;
	printf("%d\n",cev);
	return 0;
}
