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
    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i]; 
    }
    ll mini = LONG_MAX;
    ll s=0;
    for(int i=0;i<n;i++){
        s += a[i];
        ll d = sum -s;
        mini = min(mini, abs(s-d));
    }
    cout<<mini<<endl;
    return 0;
}

