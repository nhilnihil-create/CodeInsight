#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

struct robot {
	int x_min;
	int x_max;
	robot(int ix, int il) {
		x_min = ix - il;
		x_max = ix + il; 
	}
};

// ���l x_max �Ń\�[�g���邽�߂̔�r���Z�q
bool cmp_max(const robot& a, const robot& b) {
	return a.x_max > b.x_max;
}

int main() {

	int N;
	cin >> N;

	int x, l;
	vector<robot> val;
	for (int i = 0; i < N; i++) {
		cin >> x >> l;
		val.push_back(robot(x, l));
	}

	// ���{�b�g�̃A�[���̍ő�l�Ń\�[�g�i���ׂ��̏��j
	sort(val.begin(), val.end(), cmp_max);

	// ���{�b�g�̐�
	int ans = 1;

	// �S�Ẵ��{�b�g�Ɋւ����×~�@�ŒT��
	robot dval = val.back();
	robot nval = robot(0, 0);
	val.pop_back();
	while (val.size() > 0) {
		// �c�����{�b�g������
		nval = dval;

		while (val.size() > 0 && nval.x_max > dval.x_min) {
			dval = val.back();
			val.pop_back();
		}

		// ���{�b�g�̐����X�V
		ans += 1;
	}

	// �Ō�̃��{�b�g�̊m�F
	if (nval.x_max > dval.x_min) {
		// �ߏ�ɐ����グ�������폜
		ans -= 1;
	}

	cout << ans << endl;

	return 0;
}

