#include<cstdio>
#define S(n) scanf("%d",&n)
int n,q,i,j,s[10000],t,c;
main(){  
  for(S(n);i<n;S(s[i++]));
  for(S(q);j<q;++j)
    for(S(t),i=0;i<n;++i)
      if(t==s[i])c++,i=n;
  printf("%d\n",c);
}