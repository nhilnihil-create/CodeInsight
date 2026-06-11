/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

/*  Macros from Endagorion */
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


int main(){
        
    ios_base::sync_with_stdio(0);
    
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    string s;
    cin>>s;
    int n = s.length();
    
    vi x(n+1,0);
    for(int i=0;i<n;i++){
        if(s[i]=='<'){
            x[i+1] = max(x[i+1], x[i]+1);
        }
    }

    for(int i=n-1;i>=0;i--){
        if(s[i]=='>'){
            x[i] = max(x[i+1]+1, x[i]);
        }
    }

    i64 sum=0;
    for(int i=0;i<=n;i++)
        sum += x[i];
    cout<<sum<<endl;
    /*
    string r="";
    for(int i=0;i<n;i++){
        r += 'a';
        r += s[i];
    }
    r += 'a';
    //cout<<r<<endl;
    //cout<<r.length()<<endl;

    //vpi x(n+1);
    
    i64 sum = 0;
    for(int i=0;i<r.length();i+=2){
        int cnt_left=0, cnt_right=0;
        if(r[i-1]=='<'){
            cnt_left = 1;
            for(int j=i-1;j>=0;j-=2){
                if(r[j]==r[j-2])
                    cnt_left++;
                else
                    break;
            }
        }
        if(r[i+1]=='>'){
            cnt_right=1;
            for(int j=i+1;j<r.length();j+=2){
                if(r[j]==r[j+2])
                    cnt_right++;
                else
                    break;
            }
        }
        //cout<<"For position: "<<i<<"--> Left: "<<cnt_left<<", Right: "<<cnt_right<<", Value: "<<max(cnt_left, cnt_right)<<endl;
        sum += max(cnt_left, cnt_right);
    }
    cout<<sum<<endl;
    */
    return 0;
}

