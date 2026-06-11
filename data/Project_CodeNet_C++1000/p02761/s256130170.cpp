#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    vi num(n);
    for(int i=0;i<m;i++){
        int s,c;
        cin >> s >> c;
        if(num[s-1]!=0){
            if(num[s-1]!=c){
                cout << "-1" << endl;
                return 0;
            }
        }
        if(s-1==0&&c==0&&n>=2){
            cout << "-1" << endl;
            return 0;
        }
        num[s-1]=c;
    }
    if(num[0]==0&&n>=2) num[0]=1;
    for(int x:num){
        cout << x;
    }
    puts("");
    return 0;
}