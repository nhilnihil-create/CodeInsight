#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int,int> point;

int factorial(int N){
    if(N<=1)return 1;
    else return N*factorial(N-1);
}

double dist(point p1,point p2){
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}

int main(){
    int N;
    vector<point> coordinate;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int x,y;cin>>x>>y;
        coordinate.emplace_back(make_pair(x,y));
    }
    double res=0;
    for(int i=0;i<N;i++){
        double total=0;
        for(int j=0;j<N;j++){
            if(i==j)continue;
            total+=dist(coordinate[i],coordinate[j])*factorial(N-1);
        }
        res+=total;
    }
    res=res/factorial(N);
    cout << fixed << setprecision(7) << res << endl;
    return 0;
}