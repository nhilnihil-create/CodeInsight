#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;


int main(){
    int n;
    ll k;
    cin >> n >> k;
    map<int ,int > tenso;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        tenso[i]=a;
    }
    int loopcount = 1;
    int temp=1;
    vb machi(n+1,false);
    machi[1]=true;
    int loopfirst;
    //cout << "kanikani" << endl;
    while(1){
        temp=tenso[temp];
        if(machi[temp]){
            loopfirst=temp;
            break;
        }
        machi[temp]=true;
        loopcount++;       
        //cout << temp << endl;
    }
    //cout << "loopcont" << loopcount << endl;

    int toloopfirst=0;
    temp=1;
    while(1){
        if(temp==loopfirst) break;
        toloopfirst++;
        temp=tenso[temp];
    }
    //cout << "loopfirst " << loopfirst  << endl;

    int ans=1;
    if(k<toloopfirst){
        for(int i=0;i<k;i++){
            ans=tenso[ans];
        }
        cout << ans << endl;
        return 0;
    }
    //cout << "toloopcount" << toloopfirst << endl;
    int place;
    place=(k-toloopfirst)%(loopcount-toloopfirst);
    ans=loopfirst;
    for(int i=0;i<place;i++){
        ans=tenso[ans];
    }
    //cout << " kanikanikani 3" << endl;

    cout << ans << endl;
}