#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cou;
int m;
ll g[1000000];

int setg(int n){
    int ret=0;
    bool flg=true;
    for(int i=2;i<1000000;i++){
        g[i]=3*g[i-1]+1;
        if(g[i]>=n&&flg){
            ret=i-1;
            flg=false;
            break;
        }
    }
    return ret;
}

void insertsort(vector<int> &v,int n, int h){
    for(int i=0;i<h;i++){

        for(int j=i+h;j<n;j+=h){
            for(int k=j;k>=h;k-=h){
                if(v[k]<v[k-h])swap(v[k],v[k-h]);
                else break;
                cou++;
            }
        }

    }
}

void shell(vector<int> &v,int n){
    cou=0;
    for(int i=m;i>=1;i--){
        insertsort(v,n,g[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> vc(n);
    for(int i=0;i<n;i++)cin >> vc[i];

    g[1]=1;
    m=setg(n);
    shell(vc,n);

    cout << m << endl;
    for(int i=m;i>=1;i--)cout << g[i] << (i!=1?" ":"\n");
    cout << cou << endl;
    for(int i=0;i<n;i++){
        cout << vc[i] << endl;
    }

}

