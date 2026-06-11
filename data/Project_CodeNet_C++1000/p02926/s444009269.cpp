#include<bits/stdc++.h>

using namespace std;

struct Point{
  double x;
  double y;
  
  Point(double xi, double yi) : x(xi), y(yi){}
  
  Point& operator+=(const Point& p){
    this->x += p.x;
    this->y += p.y;
    return *this;
  }
  
  Point& operator-=(const Point& p){
    this->x -= p.x;
    this->y -= p.y;
    return *this;
  }
  
  bool operator<(const Point& p) const{
    return atan2(y, x) < atan2(p.y, p.x);
  }
};

Point operator+(const Point& p1, const Point& p2){
  return Point(p1) += p2;
}

double distance(const Point& p1, const Point& p2){
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  
  vector<Point> engines;
  for(int i = 0; i < N; i++){
    double x, y;
    cin >> x >> y;
    engines.push_back(Point(x, y));
  }
  
  sort(engines.begin(), engines.end());
  
  Point me(0, 0);
  const Point o(0, 0);
  double reach = 0;
  int low = 0;
  int high = 0;
  while(low < N){
    while(high < low + N && distance(me, o) <= distance(me + engines[high % N], o)){
      me += engines[high % N];
      high++;
    }
    reach = max(reach, distance(me, o));
    if(low == high){
      me += engines[high++];
    }
    me -= engines[low++];
  }
  
  cout << fixed << setprecision(10) << reach << endl;
  
  return 0;
}