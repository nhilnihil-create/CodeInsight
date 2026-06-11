#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
string beg;
char s[N],t[N];
ll nxt[N][26],st[26],len1,len2,id,ans=1;
int main() {
	cin>>beg,len1=beg.size();
	for(int i=1;i<=len1;i++)s[i]=beg[i-1];
	cin>>beg,len2=beg.size();
	for(int i=1;i<=len2;i++)t[i]=beg[i-1];
    for(int i=len1;i>=0;i--){
        for(int j=0;j<26;j++)nxt[i][j]=st[j];
        if(i)st[s[i]-'a']=i;
    }
    for(int i=1;i<=len2;i++){
        if(nxt[id][t[i]-'a'])id=nxt[id][t[i]-'a'];
		else{
            if(!st[t[i]-'a']){
                cout<<-1<<endl;
                return 0;
            }
            id=st[t[i]-'a'];
            ans++;
        }
    }
    cout<<(ans-1)*len1+id<<endl;
    return 0;
}