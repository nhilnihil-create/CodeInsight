    #pragma GCC optimize (2)
    #pragma G++ optimize (2)
    #include<bits/stdc++.h>
    #define INF 0x3f3f3f3f
    #define MAX 100005
    using namespace std;
    //char nc()
    //{
    //	static char buf[100000],*p1=buf,*p2=buf;
    //	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
    //}
    char nc(){return getchar();}
    int read()
    {
    	int x=0,y=1;
    	char c=nc();
    	while(!isdigit(c))
    	{
    		if(c=='-')y=-1;
    		c=nc();
    	}
    	while(isdigit(c))
    	{
    		x=(x<<1)+(x<<3)+(c^48);
    		c=nc();
    	}
    	return x*y;
    }
    int n;
    int main()
    {
    	n=read();
    	if(n==(n&(-n))) puts("No");
    	else
    	{
    		puts("Yes");
    		printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
    		for(int i=4;i+1<=n;i+=2)
    			printf("%d %d\n%d %d\n%d %d\n%d %d\n",n+1,i,i,i+1,n+1,n+i+1,n+i+1,n+i);
    		if(!(n&1))
    		{
    			for(int i=20;i>=0;i--)
    				if((1<<i)<n)
    				{
    					if(n-(1<<i)+1==3) printf("%d %d\n%d 3",n,1<<i,n*2);
    					else printf("%d %d\n%d %d",n,1<<i,n*2,n*2-(1<<i)+1);
    					break;
    				}
    		}
    	}
    	return 0;
    }