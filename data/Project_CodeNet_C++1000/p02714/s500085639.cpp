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
    string s;
    cin>>s;
    ll r=0,g=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R')   r++;
        else if(s[i]=='G')  g++;
        else if(s[i]=='B')  b++;
    }
    ll res = r*g*b;
    //cout<<res<<endl;
    for(int j=0;j<n;j++){
        for(int d=1;d<n;d++){
            int i = j-d, k=j+d;
            if(i>=0 && k<n && s[i]!=s[j] && s[j]!=s[k] && s[i]!=s[k])   res--;
        }
    }
    cout<<res<<endl;
    /*
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(s[i]=='R' && s[j]=='G' && s[k]=='B'){
                    if((j-i)!=(k-j))    cnt++;
                }
                if(s[i]=='R' && s[j]=='B' && s[k]=='G'){
                    if((j-i)!=(k-j))    cnt++;
                }
                if(s[i]=='G' && s[j]=='R' && s[k]=='B'){
                    if((j-i)!=(k-j))    cnt++;
                }
                if(s[i]=='G' && s[j]=='B' && s[k]=='R'){
                    if((j-i)!=(k-j))    cnt++;
                }
                if(s[i]=='B' && s[j]=='R' && s[k]=='G'){
                    if((j-i)!=(k-j))    cnt++;
                }
                if(s[i]=='B' && s[j]=='G' && s[k]=='R'){
                    if((j-i)!=(k-j))    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    vector<bool> r,g,b;
    for(int i=0;i<n;i++){
        if(s[i]=='R') r.push_back(i);
        else if(s[i]=='G')  g.push_back(i);
        else    b.push_back(i);
    }
    vector<bool> r_vis(r.size(), false);
    vector<bool> g_vis(g.size(), false);
    vector<bool> b_vis(b.size(), false);

    for(int i=0;i<r.size();)
    */
    return 0;
}


