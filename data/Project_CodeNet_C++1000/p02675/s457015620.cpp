#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
using namespace std;
template <typename T> T Max(T X,T Y){return X>Y?X:Y;}
template <typename T> T Min(T X,T Y){return X<Y?X:Y;}
template <typename T> void chmax(T &X,T Y){X=X>Y?X:Y;return;}
template <typename T> void chmin(T &X,T Y){X=X<Y?X:Y;return;}

int n,num;

int main()
{
	scanf("%d",&n);
	num=n%10;
	if(num==3) printf("bon\n");
	else if(num==0||num==1||num==6||num==8) printf("pon\n");
	else printf("hon\n");
	return 0;
}