/*
      author : Nishikawa
      created: 07.08.2020 21:34:33
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int hl,ml,h,m;
    cin >> hl >> ml >> h >> m;
    double hx,hy,mx,my;
    hx = hl*cos((60.0*h+m)/720.0*2.0*M_PI);//時針
    hy = hl*sin((60.0*h+m)/720.0*2.0*M_PI);
    mx = ml*cos(m/60.0*2.0*M_PI);//分針
    my = ml*sin(m/60.0*2.0*M_PI);
    printf("%.12lf\n",sqrt( (hx-mx)*(hx-mx) + (hy-my)*(hy-my) ));
    return 0;
}