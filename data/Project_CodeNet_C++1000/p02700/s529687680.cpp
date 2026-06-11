#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using li = long long int;
using uli = unsigned long long int;
using namespace std;

class Player {
  public:
    int hp_, attack_;
    Player(int hp, int attack) : hp_{hp}, attack_{attack} {}
    int damage() { return attack_; }
    bool alive() { return hp_ > 0; }

    void operator-=(Player p) { hp_ -= p.damage(); }
};

int main() {
    fastIO;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    Player monster1(a, b);
    Player monster2(c, d);
    while (true) {
        monster2 -= monster1;
        if (!monster2.alive()) {
            cout << "Yes";
            break;
        }

        monster1 -= monster2;
        if (!monster1.alive()) {
            cout << "No";
            break;
        }
    }
}