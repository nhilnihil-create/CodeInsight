#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;

int main(){
    int N;
    cin >> N;
    vi a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vb rem(a[N-1]+1,true);
    for(int i=0;i<N;i++){
        int j=2;
        while(a[i]*j<=a[N-1]){
            //if(!rem[a[i]*j]) break;
            rem[a[i]*j]=false;
            j++;
        }
        if(i!=0){
            if(a[i]==a[i-1])
                rem[a[i]] = false;
        }
    }

    int count=0;
    for(int i=0;i<N;i++){
        if(rem[a[i]]){
            count++;
        }
    }
    cout << count << endl;

    return 0;
}