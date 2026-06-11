#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct Position{
    double x;
    double y;
    Position(double x, double y) : x(x), y(y) {}
};

void Koch(Position p1, Position p2, vector<Position>& k, int n) {
    if (n == 0) return;
    Position s((2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3);
    Position t((2 * p2.x + p1.x) / 3, (2 * p2.y + p1.y) / 3);
    double u_x = (t.x - s.x) / 2 - sqrt(3) * (t.y - s.y) / 2 + s.x;
    double u_y = sqrt(3.0) * (t.x - s.x) / 2 + (t.y - s.y) / 2 + s.y;
    Position u(u_x, u_y);
    Koch(p1, s , k, n - 1);
    k.push_back(s);
    Koch(s , u , k, n - 1);
    k.push_back(u);
    Koch(u , t , k, n - 1);
    k.push_back(t);
    Koch(t , p2, k, n - 1);
}

int main(){
    int n;
    cin >> n;
    Position p1(0 , 0);
    Position p2(100, 0);
    vector<Position> k;
    k.push_back(p1);
    Koch(p1, p2, k, n);
    k.push_back(p2);
    for (const auto& e : k) {
        cout << e.x << " " << e.y << endl;
    }
    return 0;
}