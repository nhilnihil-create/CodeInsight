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

int main(){
    int n;
    cin >> n;
    pair<int,int> p[n];
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
    }

    vector<int> num;
    vector<double> dist; 
    for(int i=0;i<n;i++) num.push_back(i);

    //for(int i=0;i<n;i++) cout << num.at(i);
    //cout << endl;
    
    do{
        double l=0;
        for(int i=1;i<n;i++){
            l = pow(pow((p[num[i-1]].first-p[num[i]].first),2)+pow((p[num[i-1]].second-p[num[i]].second),2),0.5);
            //cout << fixed << setprecision(8) << l << endl;
            dist.push_back(l);
        }
    }while(next_permutation(num.begin(),num.end()));

    double sum=0;
    for(int i=0;i<dist.size();i++) sum += dist.at(i);
    /*cout << endl;
    cout << sum << endl;
    cout << dist.size() << endl;
    cout << endl;*/
    int f=1;
    for(int i=1;i<=n;i++) f*=i; 
    cout << fixed << setprecision(8) << sum/f << endl;
}