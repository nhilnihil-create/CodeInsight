#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>

using namespace std;
struct wait_que {
	string name;
	int time;
	int cmp_flg;
};
void completeProcess(int size, int q);

static vector<struct wait_que> wqs;

int main()
{
	string str;
	getline(cin, str);
	// get number
	int cnt = 0;
	int num[2];
	string buff;
	stringstream ss(str);
	while (getline(ss, buff, ' ')) {
		stringstream ss_buf(buff);
		ss_buf >> num[cnt];
		cnt++;
	}

	int counter = 0;
        int total_time = 0;
	cnt = num[0];
        int q = num[1];
	int target_num = 0;
	while (true) {
		if (counter < num[0]) {
		getline(cin, str);

		struct wait_que obj;

		int split_num = str.find_first_of(' ');
		obj.name = str.substr(0, split_num);

		string time_str = str.substr(split_num + 1, str.size() - split_num);
		stringstream time_ss(time_str);
		time_ss >> obj.time;
		
		obj.cmp_flg = 0;

                wqs.push_back(obj);
                counter++;
                }

                // check target element.
		struct wait_que *tmp = &wqs[target_num];

		if ((*tmp).time - q > 0) {
			(*tmp).time -= q;
			total_time += q;
			target_num = (target_num + 1) % cnt;
		} else {
			total_time += (*tmp).time;
			cout << (*tmp).name << " " << total_time << endl;
			wqs.erase(wqs.begin() + target_num);
			cnt--;
			if (cnt == 0) {
				break;
			} else {
				target_num = target_num % cnt;
			}
		}
	}
	//completeProcess(ary, num[0], num[1]);

}

void completeProcess(int size,  int q) {
	int total_time = 0;
	int cnt = size;
	int target_num = 0;
	while (true) {
		// check target element.
		struct wait_que *tmp = &wqs[target_num];

		if ((*tmp).time - q > 0) {
			(*tmp).time -= q;
			total_time += q;
			target_num = (target_num + 1) % cnt;
		} else {
			total_time += (*tmp).time;
			cout << (*tmp).name << " " << total_time << endl;
			wqs.erase(wqs.begin() + target_num);
			cnt--;
			if (cnt == 0) {
				break;
			} else {
				target_num = target_num % cnt;
			}
		}
	}
	return;
}