#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
 
    pair<int, int> even_nodes(n, 1);
    pair<int, int> odd_nodes(n / 2 + 2, n / 2);

    for (int i = 0; i < m; ++i){
        if (i % 2 == 0) {
            cout << even_nodes.first-- << " " << even_nodes.second++ << endl;
        } else {
            cout << odd_nodes.first++ << " " << odd_nodes.second-- << endl;
        }
    }

    return 0;
}