#include <iostream>
#include <vector>
 
struct req_t
{
    int a;
    int b;
    int c;
    int d;
};
 
int calc_score(int a[10], std::vector<req_t> const &reqs)
{
    int score = 0;
    for (auto const &req : reqs)
    {
        if (a[req.b - 1] - a[req.a - 1] == req.c)
        {
            score += req.d;
        }
    }
    return score;
}
 
int main()
{
    int N, M, Q;
    std::cin >> N >> M >> Q;
    std::vector<req_t> reqs(Q);
    for (int i = 0; i < Q; i++)
    {
        auto &&req = reqs[i];
        std::cin >> req.a >> req.b >> req.c >> req.d;
    }
    int max = 0;
    int a[10];
    for (a[0] = 1; a[0] <= M; a[0]++)
    {
        for (a[1] = a[0]; a[1] <= M; a[1]++)
        {
            if (N == 2)
            {
                int score = calc_score(a, reqs);
                if (max < score)
                    max = score;
                continue;
            }
            for (a[2] = a[1]; a[2] <= M; a[2]++)
            {
                if (N == 3)
                {
                    int score = calc_score(a, reqs);
                    if (max < score)
                        max = score;
                    continue;
                }
                for (a[3] = a[2]; a[3] <= M; a[3]++)
                {
                    if (N == 4)
                    {
                        int score = calc_score(a, reqs);
                        if (max < score)
                            max = score;
                        continue;
                    }
                    for (a[4] = a[3]; a[4] <= M; a[4]++)
                    {
                        if (N == 5)
                        {
                            int score = calc_score(a, reqs);
                            if (max < score)
                                max = score;
                            continue;
                        }
                        for (a[5] = a[4]; a[5] <= M; a[5]++)
                        {
                            if (N == 6)
                            {
                                int score = calc_score(a, reqs);
                                if (max < score)
                                    max = score;
                                continue;
                            }
                            for (a[6] = a[5]; a[6] <= M; a[6]++)
                            {
                                if (N == 7)
                                {
                                    int score = calc_score(a, reqs);
                                    if (max < score)
                                        max = score;
                                    continue;
                                }
                                for (a[7] = a[6]; a[7] <= M; a[7]++)
                                {
                                    if (N == 8)
                                    {
                                        int score = calc_score(a, reqs);
                                        if (max < score)
                                            max = score;
                                        continue;
                                    }
                                    for (a[8] = a[7]; a[8] <= M; a[8]++)
                                    {
                                        if (N == 9)
                                        {
                                            int score = calc_score(a, reqs);
                                            if (max < score)
                                                max = score;
                                            continue;
                                        }
                                        for (a[9] = a[8]; a[9] <= M; a[9]++)
                                        {
                                            int score = calc_score(a, reqs);
                                            if (max < score)
                                                max = score;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << max << std::endl;
}