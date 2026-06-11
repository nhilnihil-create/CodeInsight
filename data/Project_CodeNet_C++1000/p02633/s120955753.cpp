#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
using namespace std;
int n;I int gcd(CI x,CI y) {return y?gcd(y,x%y):x;}
int main()
{
	return scanf("%d",&n),printf("%d\n",360/gcd(360,n)),0;
}