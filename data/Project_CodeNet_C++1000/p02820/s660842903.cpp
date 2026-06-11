#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int point(char a,int r,int s,int p){
    if(a=='r') return p;
    if(a=='s') return r;
    if(a=='p') return s;
    return 0;
}

int main(){
    int n,k,r,s,p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;

    int m = n/k +1;
    vector<vector<char> > h(m,vector<char>(k,'x'));

    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            if(i*k+j>=n) break;
            h.at(i).at(j)=t.at(i*k+j);
        }
    }

    /*cout << endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cout << h.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    int sum[k];
    for(int i=0;i<k;i++) sum[i]=0;

    for(int i=0;i<k;i++){
        int ser=0;
        sum[i]+=point(h.at(0).at(i),r,s,p);
        for(int j=1;j<m;j++){
            if(h.at(j).at(i)=='x') break;

            if(h.at(j-1).at(i)==h.at(j).at(i)){
                ser++;
                if(ser%2==0) sum[i]+=point(h.at(j).at(i),r,s,p);
            }else{
                ser=0;
                sum[i]+=point(h.at(j).at(i),r,s,p);
            }
        }
    }

    /*cout << endl;
    for(int i=0;i<k;i++) cout << sum[i] << endl;
    cout << endl;*/
    
    int sumsum=0;
    for(int i=0;i<k;i++) sumsum+=sum[i];

    cout << sumsum << endl;
}