#include <iostream>
#include <cstring>
#define int64 long long int
using namespace std;
int main(){
    int n ;
    scanf("%d",&n);
    char str[n] ;
    scanf("%s",str);
    int64 ret = 0 ;
    for(int i=0;str[i];i++){
        if(str[i]=='R')str[i]='0';
        else if(str[i]=='G')str[i]='1';
        else str[i] = '2';
    }
    int cnt[3] = {0} ;
    for(int j=0;j<n;j++) cnt[str[j]-'0']++;

    int c[3] = {0};
    for(int i=0;i<n;i++){
        int d = str[i] - '0' ;
        cnt[d]--;
        ret += 1LL * c[(d+1)%3] * cnt[(d+2)%3] + 1LL * c[(d+2)%3] * cnt[(d+1)%3] ;
        int j=i-1,k=i+1;
        while(j>=0 && k<n){
            if( str[j]!=str[i] && str[i]!=str[k] && str[k]!=str[j] )ret--;
            --j;
            ++k;
        }
        c[d]++;
    }
    printf("%lld\n",ret);
}