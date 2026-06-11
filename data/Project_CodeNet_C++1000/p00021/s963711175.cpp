#include <iostream>
using namespace std;
struct point{
double x;
double y;
};
int main(){
point *p = new point[4];
int n;
cin >> n;
for(;n;n--){
cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y;
if((p[0].y-p[1].y)/(p[0].x-p[1].x)==(p[2].y-p[3].y)/(p[2].x-p[3].x))
cout << "YES" << endl;
else
cout << "NO" << endl;
}
delete []p;
}