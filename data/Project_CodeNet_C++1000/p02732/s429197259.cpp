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
int main(){
    int n;
    cin >> n;
    pair<int64_t,int64_t> a[n];
    for(int i=0;i<n;i++){
        a[i].first = i+1;
        cin >> a[i].second;
    }

    for(int i=0;i<n;i++) swap(a[i].first,a[i].second);//2番目の値でソート開始
    sort(a,a+n);
    for(int i=0;i<n;i++) swap(a[i].first,a[i].second);//ソート終了

    int64_t c[n];
    for(int i=0;i<n;i++) c[i]=0;
    c[a[0].second-1]=1;
    for(int i=1;i<n;i++) {
        if(a[i-1].second==a[i].second) {
            c[a[i-1].second-1]++;
        }else{
            c[a[i].second-1]++;
        }
    }

    //cout << endl;
    //for(int i=0;i<n;i++) cout << c[i];

    int64_t d[n];
    for(int i=0;i<n;i++) d[i]=0;
    for(int i=0;i<n;i++){
        if(c[i]>=2) d[i]=c[i]*(c[i]-1)/2;
    }

    //cout << endl;
    //for(int i=0;i<n;i++) cout << d[i];

    int64_t sumcon=0;
    for(int i=0;i<n;i++) sumcon += d[i];

    //cout << endl;
    //cout << sumcon << endl;
    //cout << endl;

    int64_t s[n];
    for(int i=0;i<n;i++) s[i]=0;
    for(int i=0;i<n;i++){
        //cout << c[a[i].second-1] << endl;
        if(c[a[i].second-1]<=1) {
            s[a[i].first-1]=sumcon;
        }else{
            s[a[i].first-1]=sumcon-(c[a[i].second-1]-1);
        }   
    }
    //cout << endl;

    for(int i=0;i<n;i++) cout << s[i] << endl;
}