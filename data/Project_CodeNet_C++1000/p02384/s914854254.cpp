#include <iostream>
#include <array>
#include <string>

using namespace std;

constexpr int SURFACE_NUM = 6;
enum {TOP, FRONT, RIGHT, LEFT, BACK, BOTTOM};

class Dice {
private:
    array<int, SURFACE_NUM> m_surface;

public:
    Dice(array<int, SURFACE_NUM> surface)
        : m_surface(surface) {}

    int surface(int i) const
    {
        return m_surface.at(i);
    }

    void roll(char direction)
    {
        switch (direction) {
        case 'N':
            roll(TOP, FRONT, BOTTOM, BACK);
            break;
        case 'S':
            roll(TOP, BACK, BOTTOM, FRONT);
            break;
        case 'E':
            roll(TOP, LEFT, BOTTOM, RIGHT);
            break;
        case 'W':
            roll(TOP, RIGHT, BOTTOM, LEFT);
            break;
        }
    }

    void roll(int i, int j, int k, int l)
    {
        int tmp = m_surface.at(i);
        m_surface.at(i) = m_surface.at(j);
        m_surface.at(j) = m_surface.at(k);
        m_surface.at(k) = m_surface.at(l);
        m_surface.at(l) = tmp;
    }

    void spin()
    {
        int tmp = m_surface.at(FRONT);
        m_surface.at(FRONT) = m_surface.at(LEFT);
        m_surface.at(LEFT) = m_surface.at(BACK);
        m_surface.at(BACK) = m_surface.at(RIGHT);
        m_surface.at(RIGHT) = tmp;
    }

    int right(int top, int fr)
    {
        if (m_surface.at(RIGHT) == top || m_surface.at(LEFT) == top) {
            (*this).roll('E');
        }
        while (m_surface.at(TOP) != top) {
            (*this).roll('N');
        }
        while (m_surface.at(FRONT) != fr) {
            (*this).spin();
        }

        return m_surface.at(RIGHT);
    }

    void printDice()
    {
        cout << m_surface.at(TOP) << m_surface.at(FRONT)
             << m_surface.at(RIGHT) << m_surface.at(LEFT)
             << m_surface.at(BACK) << m_surface.at(BOTTOM) << endl;
    }
};

int main()
{
    array <int, SURFACE_NUM> init;
    for (auto i = 0; i < SURFACE_NUM; i++) {
        cin >> init.at(i);
    }
    Dice one(init);

    int n;
    cin >> n;
    while (n--) {
        int top, fr;
        cin >> top >> fr;
        cout << one.right(top, fr) << endl;
    }
}