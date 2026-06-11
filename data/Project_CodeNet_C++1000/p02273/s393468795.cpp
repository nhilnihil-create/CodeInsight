#include <list>
#include <utility>
#include <cmath>
#include <cstdio>

using namespace std;

typedef list<pair<double, double> > mylist;
typedef mylist::iterator myitr;

double c = cos(M_PI / 3);
double s = sin(M_PI / 3);

void koch(mylist &lst, int order)
{
	if (order > 0) {
		myitr it1 = lst.begin();
		myitr it2 = lst.begin();
		it2++;
		while (it2 != lst.end()) {
			double x0 = (*it1).first;
			double y0 = (*it1).second;
			double x1 = (*it2).first;
			double y1 = (*it2).second;
			double dx = (x1 - x0) / 3;
			double dy = (y1 - y0) / 3;
			lst.insert(it2, make_pair(x0 + dx, y0 + dy));
			lst.insert(it2,	make_pair(x0 + dx + dx * c - dy * s,
						              y0 + dy + dx * s + dy * c));
			lst.insert(it2, make_pair(x1 - dx, y1 - dy));
			it1 = it2;
			it2++;
		}
		koch(lst, order - 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	mylist lst;
	lst.push_back(make_pair(0, 0));
	lst.push_back(make_pair(100, 0));
	koch(lst, n);

	myitr it = lst.begin();
	while(it != lst.end()) {
		printf("%.8f %.8f\n", (*it).first, (*it).second);
		it++;
	}

	return 0;
}