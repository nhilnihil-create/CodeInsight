#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<pair<int,int>>a;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        vec.at(i)=i;
    }
     double sum=0;
    do{
        for(int i=0;i<N-1;i++){
        double c=(a.at(vec.at(i)).first-a.at(vec.at(i+1)).first)*(a.at(vec.at(i)).first-a.at(vec.at(i+1)).first);
        double b=(a.at(vec.at(i)).second-a.at(vec.at(i+1)).second)*(a.at(vec.at(i)).second-a.at(vec.at(i+1)).second);
        sum+=sqrt(c+b);
        }
    }while(next_permutation(vec.begin(),vec.end()));
    double waru=1;
    for(int i=1;i<=N;i++){
        waru*=i;
    }
    cout<< fixed << setprecision(10)<<sum/waru<<endl;


}