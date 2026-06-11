#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#include <iterator> // std::back_inserter

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    //    vector<tuple<int, int, int>> result;

    n = v.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int ti = v[i];
                int tj = v[j];
                int tk = v[k];
                if ((ti != tj && ti != tk && tj != tk) && ((tk > ti && tk > tj && ti + tj > tk) || (tj > ti && tj > tk && ti + tk > tj) || (ti > tk && ti > tj && tk + tj > ti)))
                {
                    //                    vector<int> tv = {ti, tj, tk};
                    //                    sort(tv.begin(), tv.end());
                    auto tpl = make_tuple(i, j, k);
                    //                    std::vector<tuple<int, int, int>>::iterator itr;
                    //                    itr = std::find(result.begin(), result.end(), tpl);
                    //                    if (itr == result.end())
                    //                    {
                    count++;
                    //                    result.push_back(tpl);
                    //                    }
                }
            }
        }
    }

    //    for (auto it : result)
    //    {
    //        cout << get<0>(it) + 1 << "," << get<1>(it) + 1 << "," << get<2>(it) + 1 << endl;
    //    }
    cout << count << endl;
}
