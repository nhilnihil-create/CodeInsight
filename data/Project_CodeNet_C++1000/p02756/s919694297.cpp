#include <iostream>
#include <deque>

int main()
{
    std::string s;
    std::cin >> s;

    std::deque<char> dq;
    for (const char& ch : s)
        dq.push_back(ch);

    int Q;
    std::cin >> Q;

    bool rev = false;
    for (int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        if (T == 1)
            rev = !rev;
        else {
            int F;
            char C;
            std::cin >> F >> C;
            if (F == 1)
                if (rev)
                    dq.push_back(C);
                else
                    dq.push_front(C);
            else
                if (rev)
                    dq.push_front(C);
                else
                    dq.push_back(C);
        }
    }

    std::string res;
    if (rev)
        while (!dq.empty()) {
            res += dq.back();
            dq.pop_back();
        }
    else
        while (!dq.empty()) {
            res += dq.front();
            dq.pop_front();
        }

    std::cout << res << std::endl;

    return 0;
}