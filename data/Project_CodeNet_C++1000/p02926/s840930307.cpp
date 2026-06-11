#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> P;
int main() {
    int n;
    cin >> n;
    vector<P>pts(n);
  
    for (P &p:pts) 
        cin>>p.first>>p.second;

    sort(pts.begin(), pts.end(), [](P p1, P p2){
        
         return atan2(p1.first, p1.second) < atan2(p2.first, p2.second);
         
    });

    double ans = 0;
   
    for (int i=0;i<n;i++) {
        vector<int>v;
        double y=0,x=0;
        for (int j=i; j<i+n;j++) {
            v.push_back(j);
            auto p=pts[j%n];

            y += p.first;
            x += p.second;
            double cur = sqrt((x*x)+(y*y));

         ans=max(ans,cur);

        }
    }


    cout << setprecision(40) <<fixed<< ans << endl;

}
