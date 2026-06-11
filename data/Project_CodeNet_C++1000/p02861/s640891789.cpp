/*
20/7/15

*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> xy(N);
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        xy.at(i)=make_pair(x,y);
    }
    sort(xy.begin(),xy.end());
    double sum=0;
    do{
        for(int i=1;i<N;i++){
            sum+=sqrt((xy[i].first-xy[i-1].first)*(xy[i].first-xy[i-1].first)+(xy[i].second-xy[i-1].second)*(xy[i].second-xy[i-1].second));
        }
    }while(next_permutation(xy.begin(),xy.end()));
    double d=1;
    for(int i=1;i<=N;i++){
        d*=i;
    }
    printf("%.9lf\n",sum/d);
}
