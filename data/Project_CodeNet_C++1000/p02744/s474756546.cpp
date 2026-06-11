#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fr first
#define sc second
const int mod = 1e9+7;
const int N = 1e6+6;
int n;
void go(string s, char c){
    if(n==s.size()){
        cout<<s<<endl;
        return ;
    }
    for(char nxt = 'a';nxt<c;nxt++){
        go(s+nxt,c);
    }
    go(s+c,c+1);
}
int main(){
    cin>>n;
    go("",'a');
}
