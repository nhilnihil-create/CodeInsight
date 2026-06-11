#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
double sol = 0;
double c;
double x,y;
int n;
cin>>n;
vector<pair<int,int>>data;
for(int i=0;i<n;i++){
  int a,b;
  cin>>a>>b;
  data.push_back(make_pair(a,b));
}
    for(int r = 0; r < 100; r++) {
        random_shuffle(data.begin(), data.begin() + n);
        for(int i = 0; i < n; i++) {
            double x = data[i].first, y = data[i].second, c = sqrt(pow(x, 2) + pow(y, 2));
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                x += data[j].first;
                y += data[j].second;
                double length = sqrt(pow(x, 2) + pow(y, 2));
                if(length > c) c = length;
                else {
                    x -= data[j].first;
                    y -= data[j].second;
                }
            }
            sol = max(c, sol);
        }
    }
        cout<<setprecision(40)<<sol<<endl;
}    

