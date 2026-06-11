#include <iostream>
#include <vector>
#include <string>
#include <tuple>

class A
{
public:
    A()
    {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for(int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        int cnt = bubbleSort(a, n);

        show(a);
        std::cout << cnt << std::endl;
    }

    const int bubbleSort(std::vector<int>& a,  const int n)
    {
        int cnt = 0;
        bool flag = true;

        while(flag)
        {
            flag = false;

            for(int i = n - 1; i >= 1; --i)
            {
                if(a[i] < a[i - 1])
                {
                    int v = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = v;

                    flag = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void show(const std::vector<int>& a)
    {
        for(int i = 0; i < a.size(); ++i)
        {
            std::cout << a[i] << (i + 1 == a.size() ? "\n" : " ");
        }
    }
};

class B
{
public:
    B()
    {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for(int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        const int cnt = selectionSort(a, n);

        for(int i = 0; i < n; ++i)
        {
            std::cout << a[i] << (i + 1 == n ? "\n" : " ");
        }

        std::cout << cnt << std::endl;
    }

    const int selectionSort(std::vector<int>& a, const int n)
    {
        int cnt = 0;

        for(int i = 0; i < n; ++i)
        {
            int min_j = i;

            for(int j = i; j < n; ++j)
            {
                if(a[j] < a[min_j])
                {
                    min_j = j;
                }
            }

            int v = a[i];
            a[i] = a[min_j];
            a[min_j] = v;

            if(i != min_j)
            {
                cnt++;
            }
        }

        return cnt;
    }
};

class C
{
public:
    C()
    {
        int n;
        std::cin >> n;

        std::vector<std::pair<std::string, int>> v(n);
        for(int i = 0; i < n; ++i)
        {
            std::cin >> v[i].first;

            v[i].second = (int)(v[i].first[1] - '0');
            v[i].first.pop_back();
        }

        bubbleSort(v);
        selectionSort(v);

        output(bubble_v);
        output(select_v);
    }

private:
    std::vector<std::pair<std::string, int>> bubble_v;
    std::vector<std::pair<std::string, int>> select_v;

    void output(const std::vector<std::pair<std::string, int>>& v)
    {
        for(int i = 0; i < v.size(); ++i)
        {
            std::cout << v[i].first << v[i].second << (i + 1 == v.size() ? "\n" : " ");
        }

        std::cout << (judgeStable(v) ? "Stable" : "Not stable") << std::endl;
    }

    const bool judgeStable(const std::vector<std::pair<std::string, int>>& v)
    {
        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i] != bubble_v[i])
            {
                return false;
            }
        }

        return true;
    }

    void bubbleSort(const std::vector<std::pair<std::string, int>>& v)
    {
        bubble_v = v;
        bool flag = true;

        while(flag)
        {
            flag = false;

            for(int i = bubble_v.size() - 1; i > 0; --i)
            {
                if(bubble_v[i].second < bubble_v[i - 1].second)
                {
                    std::swap(bubble_v[i], bubble_v[i - 1]);
                    flag = true;
                }
            }
        }
    }

    void selectionSort(const std::vector<std::pair<std::string, int>>& v)
    {
        select_v = v;

        for(int i = 0; i < select_v.size(); ++i)
        {
            int min_j = i;

            for(int j = i; j < select_v.size(); ++j)
            {
                if(select_v[min_j].second > select_v[j].second)
                {
                    min_j = j;
                }
            }

            std::swap(select_v[i], select_v[min_j]);
        }
    }
};

int main(void)
{
    C c;
    return 0;
}