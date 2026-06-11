#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

constexpr int MAXGAPS = 13;

long g_cnt = 0;

void shellSort(vector<int>& line, const int n);
void insertionSort(vector<int>& line, const int n, const int gap);

int main()
{
    int n;
    cin >> n;

    vector<int> line(n);
    for (auto i = 0; i < n; i++) {
        cin >> line.at(i);
    }

    shellSort(line, n);

    cout << g_cnt << endl;
    for (auto i = 0; i < n; i++) {
        cout << line.at(i) << endl;
    }

    return 0;
}

void shellSort(vector<int>& line, const int n)
{
    vector<int> gap(MAXGAPS);
    int m = 1;
    gap.at(0) = m;
    int gap_cnt = 1;
    for (auto i = 1; (m = 3 * m + 1) <= n; i++) {
        gap.at(i) = m;
        gap_cnt++;
    }

    cout << gap_cnt << endl;
    for (auto i = gap_cnt - 1; i >=  0; i--) {
        cout << gap.at(i);
        if (i != 0) {
            cout << " ";
        }
    }
    cout << endl;

    for (auto i = gap_cnt - 1; i >=  0; i--) {
        insertionSort(line, n, gap.at(i));
    }
}

void insertionSort(vector<int>& line, const int n, const int gap)
{
    for (auto i = gap; i < n; i++) {
        int key = line.at(i);

        auto j = i - gap;
        while (j >= 0 && line.at(j) > key) {
            line.at(j + gap) = line.at(j);
            g_cnt++;
            j -= gap;
        }

        line.at(j + gap) = key;
    }
}