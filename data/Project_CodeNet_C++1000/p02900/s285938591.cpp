#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sigma_size 30
#define max_size (int)(1e6+50)
#define MAX (int)(1e5+7)
int qread()
{
	char c; int s=0,t=1; while ((c=getchar())<'0' || c>'9') (c=='-' && (t=-1));
	do s=s*10+c-'0'; while ((c=getchar())>='0' && c<='9'); return s*t;
}

int mark[max_size];
LL pri[max_size] , cnt = 1;
void get_pri()
{
	for ( int i = 2 ; i < 1e6+10 ; i++ )
	{
		if ( !mark[i] ) pri[cnt++] = i;
		for ( int j = 1 ; j <= cnt && i*pri[j] < 1e6+10 ; j++ )
		{
			mark[i*pri[j]] = 1;
			if ( i % pri[j] == 0 ) break;
		}
	}
}



int main ()
{
	LL A , B ;
	cin >> A >> B ;
	get_pri();
	LL g = __gcd ( A , B );
	int cnt = 1;
	for ( int i = 1 ; pri[i]*pri[i] <= g ; i++ )
	{
		if ( g % pri[i] ) continue;
		cnt++;
		while ( g % pri[i] == 0 )	g /= pri[i];
	}
	if ( g > 1 ) cnt++;
	cout << cnt << endl;
}