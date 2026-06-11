#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef std::pair<float,float> point;
typedef std::vector<point> segments;

void print_array(segments list)
{
  for(int i = 0; i < list.size(); ++i){
    std::cout << list[i].first<<" "<<list[i].second<< std::endl;
  }
}

void print_point(point pt)
{
    std::cout << pt.first<<" "<<pt.second<< std::endl;
}

void koch(int n,point p1,point p2) {
    if(n==0) {
        return;
    }

    point s=std::make_pair((2*p1.first+p2.first)/3,(2*p1.second+p2.second)/3);
    point t=std::make_pair((p1.first+2*p2.first)/3,(p1.second+2*p2.second)/3);
    float ux=(s.first+std::cos(M_PI*60/180)*(t.first-s.first)-std::sin(M_PI*60/180)*(t.second-s.second));
    float uy=(s.second+std::sin(M_PI*60/180)*(t.first-s.first)+std::cos(M_PI*60/180)*(t.second-s.second));
    point u=std::make_pair(ux,uy);
    koch(n-1, p1, s);
    print_point(s);
    koch(n-1, s, u);
    print_point(u);
    koch(n-1, u, t);
    print_point(t);
    koch(n-1, t, p2);
} 
    
int main(void){
        
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    segments segment;
    point p1=std::make_pair(0,0);
    point p2=std::make_pair(100,0);
    print_point(p1);
    koch(n,p1,p2);
    print_point(p2);
    return 0;
}