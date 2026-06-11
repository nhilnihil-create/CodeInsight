#include<bits/stdc++.h>
#define inf 1000000000
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int,int> mii;
int bp[1000001];
int exhaust(int n)
{
    int i=0;
    while(n%2==0){
        n>>=1;
        i++;
    }
    return i;
}
int main()
{
    int i,j,k;
    int n;
    string str;
    cin>>n>>str;
    bp[0]=0;
    for(i=1;i<n;i++){
        bp[i]=bp[i-1]+exhaust(n-i)-exhaust(i);
    }
    int sum=0;
    for(i=0;i<str.length();i++)
        sum+=(bp[i]==0)*(str[i]-'1');
    if(sum&1){
        printf("1");
        return 0;
    }
    for(i=0;i<str.length();i++){
        if(str[i]=='2'){
            printf("0");
            return 0;
        }
    }
    sum=0;
    for(i=0;i<str.length();i++)
        sum+=(bp[i]==0)*(str[i]-'1')/2;
    if(sum&1)
        printf("2");
    else
        printf("0");

}
