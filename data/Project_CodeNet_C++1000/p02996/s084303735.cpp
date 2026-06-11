#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task
{
    int cost;
    int limit;
};

int main()
{
    int n; cin >> n;

    vector<Task> tasks(n);

    for (auto& task : tasks)
    {
        cin >> task.cost >> task.limit;
    }

    sort(tasks.begin(), tasks.end(), [](const auto& lhs, const auto& rhs){
        return lhs.limit < rhs.limit;
    });

    int s = 0;

    for (const auto& task : tasks)
    {
        s += task.cost;

        if (s > task.limit)
        {
            cout << "No";

            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
