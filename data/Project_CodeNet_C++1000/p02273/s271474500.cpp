//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

//vector//
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

typedef pair<int,int> P;  //q(p.first,p.second)

struct Point{
    double x,y;
};

void KochCurve(int n, Point a, Point b){

    if(n==0) return;

    Point s,t,u;
    double th = M_PI * 60.0 / 180.0;
    s.x = (2.0 * a.x + 1.0 * b.x)/3.0;
    s.y = (2.0 * a.y + 1.0 * b.y)/3.0;
    t.x = (1.0 * a.x + 2.0 * b.x)/3.0;
    t.y = (1.0 * a.y + 2.0 * b.y)/3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    KochCurve(n-1, a, s);
    cout << s.x << ' ' << s.y << endl;
    KochCurve(n-1, s, u);
    cout << u.x << ' ' << u.y << endl;
    KochCurve(n-1, u, t);
    cout << t.x << ' ' << t.y << endl;
    KochCurve(n-1, t, b);
}

int main (){
    int n;
    cin >> n;

    Point a,b;
    a.x = 0.0;
    a.y = 0.0;
    b.x = 100.0;
    b.y = 0.0;

    // cout << a.x << ' ' << a.y << endl;
    printf("%.8f %.8f\n",a.x,a.y);
    KochCurve(n, a, b);
    // cout << b.x << ' ' << b.y << endl;
    printf("%.8f %.8f\n",b.x,b.y);

}
