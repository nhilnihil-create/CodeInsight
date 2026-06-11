#include<bits/stdc++.h>
using namespace std;
const bool debug =0;

inline void read(long long &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar())if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}

inline void write(long long x){
    static const long long maxlen=100;
    static char s[maxlen];
    if (x<0) {   putchar('-'); x=-x;}
    if(!x){ putchar('0'); return; }
    long long len=0; for(;x;x/=10) s[len++]=x % 10+'0';
    for(long long i=len-1;i>=0;--i) putchar(s[i]);
}

const long long MAXN = 1100000;

long long a[ MAXN ];
long long b[ MAXN ];
long long n;

typedef pair<long long,long long> PII;
priority_queue< PII > Q;

int main(){
    read(n);
    for (long long i=0;i<n;i++)
        read(a[i]);

    for (long long i=0;i<n;i++)
    {
        read(b[i]);
        Q.push( make_pair( b[i] , i  ) );
    }

    long long cnt=0;
    while (Q.size())
    {
        PII tmp=Q.top();
        Q.pop();

        long long val=tmp.first;
        long long id=tmp.second;
        if ( val == a[id] )
            continue;

        if ( val < b[ (id+n-1)%n ] + b[ (id+1)%n ] + a[id] )
        {
            puts("-1");
            exit(0);
        }

        long long sum=b[ (id+n-1)%n ] + b[ (id+1)%n ];

        long long kkk=( val - a[id] ) / sum ;
        cnt+=kkk;
        val = val - kkk*sum ;

        b[id]=val;
        Q.push( make_pair( val , id ) );
    }

    cout<<cnt<<endl;
    return 0;
}
