#include<iostream>
#include<set>
#include<math.h>
using namespace std;
int main(){
    int n;
    int m;
    cin>>n>>m;
//    set<pair<int,int>> points;
    int ans=0;
    for(int k=0;k<n;k++){
        double a,b;
        cin>>a>>b;
        pair<int,int> point(a,b);
//        if(points.count(point)){
//            continue;
//        }
//        points.insert(point);
        double an=sqrt(pow(a,2)+pow(b,2));
//        cout<<"ans: "<<an<<endl;
        if(an<=m){

           ans++;
//           cout<<"a"<<point.first<<" "<<point.second<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
