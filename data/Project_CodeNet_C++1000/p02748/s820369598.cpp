/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    int a,b,m;
    cin>>a>>b>>m;
    int r[a], w[b];
    int min_r = INT_MAX, min_w = INT_MAX;
    for(int i=0;i<a;i++)    cin>>r[i], min_r = min(min_r, r[i]);
    for(int i=0;i<b;i++)    cin>>w[i], min_w = min(min_w, w[i]);
    int sum = min_r + min_w;
    while(m--){
        int x,y,c;
        cin>>x>>y>>c;
        x--,y--;
        sum = min(sum,r[x]+w[y]-c);
    }
    cout<<sum<<endl;
    return 0;
}

