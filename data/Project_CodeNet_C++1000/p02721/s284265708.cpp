#include <bits/stdc++.h>
using namespace std;
 
const int N=200005;

int n,k,c;
int a[N],b[N];
char s[N];

void init()
{scanf("%d %d %d",&n,&k,&c);
 scanf("%s",s+1);
}

void work()
{int pos=0;
 for (int i=1;i<=n;i++)
   if (s[i]=='o')
     {a[++pos]=i;
      if (pos>=k) break;
      i+=c;
     }
 pos=k;
 for (int i=n;i>=1;i--)
   if (s[i]=='o')
     {b[pos--]=i;
      if (pos<=0) break;
      i-=c;
	 }
 for (int i=1;i<=k;i++)
   if (a[i]==b[i])
     printf("%d\n",a[i]);  
}

int main()
{
 init();
 work();
 return 0;
}
