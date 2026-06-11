#include <iostream>
#include <vector>

using namespace std;

class Vertex
{
public:
    int number_of_edges;
    vector<int> edges;
};

int main()
{
    int n;
    cin >> n;

    vector<Vertex> adjacency_list(n);
    for (int i = 0; i < n; ++i) {
        int index;
        cin >> index >> adjacency_list[i].number_of_edges;

        adjacency_list[i].edges.resize(adjacency_list[i].number_of_edges);
        for (int j = 0; j < adjacency_list[i].number_of_edges; ++j)
            cin >> adjacency_list[i].edges[j];
    }

    vector<vector<int>> adjacency_matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < adjacency_list[i].number_of_edges; ++j)
            adjacency_matrix[i][adjacency_list[i].edges[j] - 1] = 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << adjacency_matrix[i][0];
        for (int j = 1; j < n; ++j)
            cout << ' ' << adjacency_matrix[i][j];
        cout << '\n';
    }
}

